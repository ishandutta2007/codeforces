Program arsijo;
Var n, i, a, min, max, maxI, minI: longint;
        ar: array [1..100] of longint;
Begin
    Read(n);
    for i:=1 to n do
        Read(ar[i]);
    min := ar[1];
    max := ar[1];
    minI := 1;
    maxI := 1;
    for i:=2 to n do
    begin
        if ar[i] > max then
        begin
            max := ar[i];
            maxI := i;
        end;
        if ar[i] <= min then
        begin
            min := ar[i];
            minI := i;
        end;
    end;
    a := (n - minI) + (maxI - 1);
    if minI < maxI then
        dec(a);
    WriteLn(a);
End.