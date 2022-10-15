Program arsijo;
Var i, n: longint;
Begin
        Read(n);
        if n <= 3 then
                WriteLn('NO') else
        begin
            if n mod 2 = 0 then
            begin
                WriteLn('YES');
                WriteLn('1 * 2 = 2');
                WriteLn('2 * 3 = 6');
                WriteLn('6 * 4 = 24');
                for i:=5 to n do
                        if i mod 2 = 0 then
                        begin
                            WriteLn(i, ' - ', i-1, ' = 1');
                            WriteLn('1 * 24 = 24');
                        end;
            end else
            begin
                WriteLn('YES');
                WriteLn('2 - 1 = 1');
                WriteLn('1 + 3 = 4');
                WriteLn('4 * 5 = 20');
                WriteLn('20 + 4 = 24');
                for i:=7 to n do
                        if i mod 2 = 1 then
                        begin
                            WriteLn(i, ' - ', i-1, ' = 1');
                            WriteLn('1 * 24 = 24');
                        end;
            end;
        end;
End.