Program arsijo;
Var a, b, c, d, x, n, i: longint;
Begin
    a := 0;
    b := 0;
    for i:=1 to 3 do
    begin
        Read(x);
        inc(a, x);
    end;
    for i:=1 to 3 do
    begin
        Read(x);
        inc(b, x);
    end;
    Read(n);
    //WriteLn(a);
    //WriteLn(b);
    c := a div 5;
    if a mod 5 <> 0 then
        inc(c);
    d := b div 10;
    if b mod 10 <> 0 then
        inc(d);
    if c + d <= n then
        WriteLn('YES') else
        WriteLn('NO');
End.