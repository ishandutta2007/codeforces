Program arsijo;
Var a, m, i: longint;
Begin
        ReadLn(a, m);
        while m mod 2 = 0 do m := m div 2;
        if a mod m = 0 then
                WriteLn('Yes') else
                WriteLn('No');
End.