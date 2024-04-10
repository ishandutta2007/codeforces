Program arsijo;
Var n, i, max, min, a, b: longint;
Begin
    Read(n);
    Read(min);
    max := min;
    b := 0;
    for i:=2 to n do
    begin
        Read(a);
        if a > max then
        begin
            max := a;
            inc(b);
        end;
        if a < min then
        begin
            min := a;
            inc(b);
        end;
    end;
    WriteLn(b);
End.