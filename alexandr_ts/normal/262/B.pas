var n,m,i,j,k,t,done:longint;
    v:array[1..100000]of longint;
procedure qSort(l,r:longint);
var i,j:longint;
     w,q:longint;
begin
   i := l; j := r;
   q := abs(v[(l+r) div 2]);
   repeat
     while (abs(v[i]) < q) do inc(i);
     while (q < abs(v[j])) do dec(j);
     if (i <= j) then
     begin
       w:=(v[i]); v[i]:=v[j]; v[j]:=w;
       inc(i); dec(j);
     end;
   until (i > j);
   if (l < j) then qSort(l,j);
   if (i < r) then qSort(i,r);
end;
begin
  read(n,m);
  k:=0;
  for i:=1 to n do
    read(v[i]);
qSort(1,n);

    for i:=n downto 1 do
      begin
        if v[i]<0 then
          begin
            v[i]:=v[i]*(-1);
            inc(k);
          end;
        if k=m then break;
      end;
  if (m-k)mod 2=1 then v[1]:=v[1]*(-1);
  for i:=1 to n do
    inc(done,v[i]);
  write(done);
end.