Program arsijo;
Var a: int64;
        n, i, m: longint;
Begin
        Read(n, m);
        a := 0;
        while true do
        for i:=1 to n do
        begin
            if a > m then
            begin
               // WriteLn(a,' ', m, ' ', i);
                if i=1 then dec(a, n) else dec(a, i-1);
                WriteLn(m - a);
                exit;
            end;
            inc(a, i);
        end;

End.