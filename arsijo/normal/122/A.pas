Program arsijo;
Var a, b: longint;
Begin
    Read(a);
    if (a mod 4 = 0) or (a mod 7 = 0) or
    (a mod 47 = 0) or (a mod 77 = 0)  or
    (a mod 74 = 0) or (a mod 474 = 0)   or
    (a mod 477 = 0) or (a mod 747 = 0) or
    (a mod 774 = 0) or (a mod 777 = 0) then
        WriteLn('YES') else
        WriteLn('NO');
End.