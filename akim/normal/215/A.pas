var a,b:array[1..100]of longint;
    n,m,i,f,k,l:longint;
begin
 readln(n);
 for i:=1 to n do
  read(a[i]);
 readln(m);
 for i:=1 to m do
  read(b[i]);
 k:=0;l:=0;
 for i:=1 to n do
  for f:=1 to m do
   if (b[f]mod a[i]=0)and(b[f]div a[i]>k)then begin l:=1;k:=b[f]div a[i];end else
    if (b[f]mod a[i]=0)and(b[f]div a[i]=k)then begin inc(l);end;
 writeln(l);
end.