Program arsijo;
Var a, i, j: longint;
        s: ansiString;
{Function sq(q, w: longint): int64;
Var r: longint;
        e: int64;
begin
    e := 1;
    for r :=1 to w do
        e := e * q;
    exit(e);
end; }
Begin
        {ReadLn(s);
        Val(s[length(s)], a, i);
        if a mod 5 = 4 then WriteLn(4) else WriteLn(0);}
 {       for i:=1 to 20 do
                WriteLn((sq(1, i) mod 10) + (sq(2, i) mod 10) + (sq(3, i) mod 10) + (sq(4, i) mod 10));
}
        ReadLn(s);
        Val(s[length(s)], a, i);
        j := 0;
        if length(s) <> 1 then val(s[length(s)-1], j, i);
        if j <> 0 then a := j * 10 + a;
        if a mod 4 = 0 then WriteLn(4) else WriteLn(0);
End.