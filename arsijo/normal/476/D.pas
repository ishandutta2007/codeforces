uses Math;
Var k, m, i, n, x, j, ans: longint;
    ar: array [1..20000, 1..4] of longint;
Begin
    ReadLn(n, k);
    j:=1;
    for i:=1 to n do
    begin
        ar[i, 1] := j;
        ar[i, 2] := j + 2;
        ar[i, 3] := j + 4;
        ar[i, 4] := j + 1;
        x := max(x, j+4);
        inc(j, 6);
    end;
    WriteLn(x*k);
    for i:=1 to n do
        WriteLn(ar[i, 1] * k, ' ', ar[i, 2] * k, ' ', ar[i, 3] * k, ' ', ar[i, 4] * k);
End.