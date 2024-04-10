Program arsijo;
Uses math;
Var a, b, c: int64;
Begin
    Read(a);
    if a >= 0 then
        WriteLn(a) else
    begin
        a := abs(a);
        WriteLn( - min((a div 100) * 10 + (a mod 10), (a div 10)));
    end;
End.