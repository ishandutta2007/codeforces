uses math;
Var a, b, c, n, i, k, j, m: longint;
    ar: array [1..2000] of longint;
procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=ar[l+random(r-l)];
         repeat
           while ar[i]>x do
            inc(i);
           while x>ar[j] do
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
    Read(n,k);
    for i:=1 to n do read(ar[i]);
    sort(1,n);
    i:=1;
    while i<=n do
    begin
        m:=m+2*(ar[i]-1);
        i:=i+k;
    end;
    WriteLn(m);
End.