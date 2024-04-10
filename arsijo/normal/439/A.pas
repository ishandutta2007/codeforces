Program arsijo;
Var i, g, s, n, m: longint;
Begin
        ReadLn(n, m);
        s := 0;
        for i:=1 to n do
        begin
            Read(g);
            inc(s, g);
        end;
        if (s + 10*(n-1)) > m then WriteLn(-1) else
                WriteLn((m - s) div 5);
End.