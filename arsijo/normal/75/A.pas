Program arsijo;
Var x, y, z: longint;
        ans: int64;
Function get(a: longint):longint;
Var i, b: longint;
Begin
        i := 1;
        b := 0;
        while a <> 0 do
        begin
            if a mod 10 <> 0 then
            begin
                b := b + (i * (a mod 10));
                i := i * 10;
            end;
            a := a div 10;
        end;
        exit(b);
End;
Begin
        Read(x, y);
        {WriteLn(get(x));
        WriteLn(get(y));
        WriteLn(get(x+y)); }
        if get(x) + get(y) = get(x+y) then
                WriteLn('YES') else
                WriteLn('NO');
End.