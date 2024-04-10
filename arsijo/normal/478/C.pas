uses math;
Var a, b, c, n, m, k, d: int64;
    ar: array [1..3] of int64;
    i: longint;
procedure sort;
Var i, j: longint;
Begin
    for i:=1 to 2 do
        for j:=i+1 to 3 do
            if ar[j] < ar[i] then
            begin
                d := ar[i];
                ar[i] := ar[j];
                ar[j] := d;
            end;
End;
Begin
    Read(ar[1], ar[2], ar[3]);
    sort;
    WriteLn(min((ar[1] + ar[2] + ar[3]) div 3, ar[1] + ar[2]));
End.