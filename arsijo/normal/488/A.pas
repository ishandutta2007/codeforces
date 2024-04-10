Program arsijo;
Var a, b, c: int64;
Function check(t: int64): boolean;
Begin
    t := abs(t);
    while t <> 0 do
    begin
        if t mod 10 = 8 then
                exit(true);
        t := t div 10;
    end;
    exit(false);
End;
Begin
        Read(a);
        b := 1;
        inc(a);
        while true do
        begin
            if check(a) then
            begin
                WriteLn(b);
                exit;
            end;
            inc(a);
            inc(b);
        end;
End.