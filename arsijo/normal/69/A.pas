Program arsijo;
Var a, b, c, x, y, z, i, n: longint;
Begin
        Read(n);
        a := 0; b := 0; c := 0;
        for i:=1 to n do
        begin
            Read(a, b, c);
            inc(x, a);
            inc(y, b);
            inc(z, c);
        end;
        if (x = 0) and (y = 0) and (z = 0) then
                WriteLn('YES') else
                WriteLn('NO');
End.