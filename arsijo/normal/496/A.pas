Program arsijo;
Var n, i, min, max, a, b, c: longint;
        ar: array [1..100] of longint;
Begin
    Read(n);
    for i:=1 to n do
        Read(ar[i]);
    min := -1;
    a := 0;
    for i:=1 to (n-1) do
        if ((ar[i+1] - ar[i]) > a) then
                a := ar[i+1] - ar[i];
    for i:=2 to (n-1) do
    begin
        b := a;
        c := ar[i+1] - ar[i-1];
        if c > b then b := c;
        if (b < min) or (min = -1) then
                min := b;
    end;
    WriteLn(min);
End.