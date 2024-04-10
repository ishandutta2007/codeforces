var a:array[1..100]of longint;
    n,p,s,i,f,k:longint;
begin
 readln(n);
 for i:=1 to n do
 begin
  read(a[i]);
  p:=p+a[i];
 end;
 for i:=1 to n-1 do
  for f:=i+1 to n do
   if a[i]<a[f] then begin s:=a[i];a[i]:=a[f];a[f]:=s;end;
 s:=0;k:=0;
 for i:=1 to n do
 begin
  if s>p then break;
  s:=s+a[i];
  p:=p-a[i];
  k:=k+1;
 end;
 writeln(k);
end.