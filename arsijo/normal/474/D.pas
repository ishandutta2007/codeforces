Program zadacha;
Var mid, i, k, q, n, t, l, r:longInt;
    a, S:array[0..2010000] of LongInt;
Begin
    Mid:=1000000007;
    Read(n, k);
    a[0]:=1;
    for i:=0 to 1000000 do
    Begin
        a[i+1]:=(a[i]+a[i+1]) mod mid;
        a[i+k]:=(a[i]+a[i+k]) mod mid;
        if i<>0 then s[i]:=(s[i-1]+a[i]) mod mid;
    End;
    for i:=1 to n do
    Begin
        read(l, r);
        q:=s[r]-s[l-1];
        if q < 0 then q:= q + mid;
        Writeln(q);
    End;
End.