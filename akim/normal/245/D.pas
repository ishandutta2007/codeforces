var n,i,f:longint;
    a:array[1..100,1..100]of longint;
begin
 readln(n);
 for i:=1 to n do
  for f:=1 to n do
   read(a[i,f]);
 for i:=1 to n do
 begin
  a[i,i]:=0;
  for f:=1 to n do
   a[i,i]:=a[i,i] or a[i,f] or a[f,i];
 end;
 for i:=1 to n do
  write(a[i,i],' ');
end.