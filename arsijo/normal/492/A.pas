Program arsijo;
Var a, b, c, d, e, f, g, i, n: longint;
Begin
    Read(n);
    a := 0;
    b := 0;
    for i:=1 to 1000 do
    begin
        inc(b, i);
        inc(a, b);
        if a > n then
        begin
            WriteLn(i-1);
            exit;
        end else if a = n then
        begin
            WriteLn(i);
            exit;
        end;
    end;
End.