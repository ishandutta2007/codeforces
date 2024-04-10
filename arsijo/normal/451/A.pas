Program arsijo;
Uses math;
Var n, m: int64;
Begin
        ReadLn(n, m);
        if min(n, m) mod 2 = 0 then WriteLn('Malvika') else
                WriteLn('Akshat');
End.