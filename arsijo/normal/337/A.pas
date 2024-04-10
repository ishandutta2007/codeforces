Program arsijo;
uses math;
Var n, i, k, b: longint;
        ar: array [1..50] of longint;

procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=ar[l+random(r-l)];
         repeat
           while ar[i]<x do
            inc(i);
           while x<ar[j] do
            dec( j );
           if not(i>j) then
             begin
                y:=ar[i];
                ar[i]:=ar[j];
                ar[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;
Begin
    Read(n, k);
    for i:=1 to k do
        Read(ar[i]);
    sort(1, k);
    b := maxlongint;
    for i:=1 to k-n+1 do
        if ar[i+n-1] - ar[i] < b then b := ar[i+n-1] - ar[i];
    if b = maxlongint then b := 0;
    WriteLn(b);

End.