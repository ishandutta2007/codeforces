Program arsijo;
Var n, i, s, max, sum, a: longint;
Begin
    sum := 0;
    max := 0;
    Read(n, s);
    for i:=1 to n do
    begin
        Read(a);
        inc(sum, a);
        if a > max then max := a;
    end;
    if sum - max <= s then
        WriteLn('YES') else
        WriteLn('NO');
End.