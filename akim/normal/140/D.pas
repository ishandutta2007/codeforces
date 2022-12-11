var a:array[1..1000]of longint;
    n,i,f,s,x,z:longint;
procedure swap(var x,y:longint);
var z:longint;
begin z:=x;x:=y;y:=z;end;
begin
 readln(n);
 for i:=1 to n do
  read(a[i]);
 for i:=1 to n-1 do
  for f:=i+1 to n do
   if a[i]>a[f] then swap(a[i],a[f]);
 s:=0;
 for i:=1 to n do
 begin
  s:=s+a[i];
  if s>710 then break;
  inc(z);
  if s>350 then inc(x,s-350);
 end;
 writeln(z,' ',x);
end.