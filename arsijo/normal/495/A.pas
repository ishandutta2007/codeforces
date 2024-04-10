Program arsijo;
{Function canConsistOf(a, b: longint): boolean;
Begin
    case a of
    1: exit((b = 0) or (b = 1) or (b = 3) or (b = 4)
        or (b = 7) or (b = 8) or (b = 9));
    2: exit((b = 2) or (b = 8));
    3: exit((b = 3) or (b = 8) or (b = 9));
    4: exit((b = 4) or (b = 8) or (b = 9));
    5: exit((b = 5) or (
End;     }
Function get(g: longint): longint;
Begin
    case g of
    1: exit(7);
    2: exit(2);
    3: exit(3);
    4: exit(3);
    5: exit(4);
    6: exit(2);
    7: exit(5);
    8: exit(1);
    9: exit(2);
    0: exit(2);
    end;
    exit(1);
End;
Var n, i: longint;
Begin
        Read(n);
        WriteLn(get(n mod 10) * get(n div 10));

End.