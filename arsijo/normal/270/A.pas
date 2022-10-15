Program arsijo;
Var n, i, a: longint;
Begin
    Read(n);
    for i:=1 to n do
    begin
        Read(a);
        if 360 mod (180 - a) = 0 then
                WriteLn('YES') else
                WriteLn('NO');
    end;
End.