Program arsijo;
Var n, y, x, i, a, b, c: longint;
Begin
    Read(n, x, y);
    a := 0;
    while (x * 100 div n) < y do
    begin
        inc(x);
        inc(a);
    end;
    WriteLn(a);
End.