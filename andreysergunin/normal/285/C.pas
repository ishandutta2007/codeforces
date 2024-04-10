var v:array[1..300000] of longint;
    n,i:longint;
    s:int64;
procedure qSort(l,r:longint);
var i,j:longint;
    w,q:longint;
begin
  i := l; j := r;
  q := v[random (l-r)+r];
  repeat
    while (v[i] < q) do inc(i);
    while (q < v[j]) do dec(j);
    if (i <= j) then
    begin
      w:=v[i]; v[i]:=v[j]; v[j]:=w;
      inc(i); dec(j);
    end;
  until (i > j);
  if (l < j) then qSort(l,j);
  if (i < r) then qSort(i,r);
end;

begin
randomize;
read (n);
for i:=1 to n do read (v[i]);
qsort (1,n);
for i:=1 to n do
   s:=s+abs (v[i]-i);
write (s);
end.