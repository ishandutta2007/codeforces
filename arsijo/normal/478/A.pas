Var a, c, n, i, k, j, m: longint;
    b: int64;
    ar: array [1..5] of int64;
Begin
    b := 0;
    for i:=1 to 5 do Read(ar[i]);
    for i:=1 to 5 do b := b + ar[i];
    c := b div 5;
    if (c = 0) or (b mod 5 <> 0) then WriteLn(-1) else WriteLn(c);
End.