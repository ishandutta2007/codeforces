Program arsijo;
Var n, m, k, a, b, c, i, x, y: longint;
Begin
    Read(n, m, k);
    for i:=1 to n do
    begin
        Read(c);
        if c = 1 then
                inc(a) else
                inc(b);
    end;
    c := 0;
    if m < a then
        inc(c, a - m);
    dec(m, a);
    if m > 0 then inc(k, m);
    if k < b then
        inc(c, b - k);
    WriteLn(c);

End.