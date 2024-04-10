var a:array[-300..3000,0..100,1..2]of int64;
    x:array[0..100,1..2]of longint;
    i,f,n,m,g:longint;s:int64;
begin
 a[0,0,1]:=1;
 readln(n,m);
 for i:=1 to n do
  readln(x[i,1],x[i,2]);
 for i:=1 to m do
  for f:=1 to n do
  begin
   for g:=0 to n do
   if (g<>f) then
   begin
    if (x[f,1]=x[g,1])or(g=0) then a[i,f,1]:=(a[i,f,1]+a[i-x[f,1],g,2])mod 1000000007;
    if (x[f,1]=x[g,2])or(g=0) then a[i,f,1]:=(a[i,f,1]+a[i-x[f,1],g,1])mod 1000000007;
    if x[f,1]<>x[f,2] then 
     if (x[f,2]=x[g,1])or(g=0) then a[i,f,2]:=(a[i,f,2]+a[i-x[f,2],g,2])mod 1000000007;
    if x[f,1]<>x[f,2] then 
     if (x[f,2]=x[g,2])or(g=0) then a[i,f,2]:=(a[i,f,2]+a[i-x[f,2],g,1])mod 1000000007;
   end;
  end;
 s:=0;
 for i:=1 to n do
  s:=(s+a[m,i,1]+a[m,i,2])mod 1000000007;
 writeln(s);
end.