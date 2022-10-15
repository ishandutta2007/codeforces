Program arsijo;
Var a, b: int64;
Begin
    Read(a);
    a := abs(a);
    b := 0;
    while true do
    begin
        if (a <= 0) and ( (-a) mod 2 = 0) then
                break;
        inc(b);
        dec(a, b);
    end;
    WriteLn(b);
End.