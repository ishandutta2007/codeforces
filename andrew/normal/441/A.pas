var
 c,b:array[1..1000] of longint;
 a:array[1..50,1..50] of longint;
 a1,d,n,i,j,l,v,k,s:longint;
begin
 readln(n,v);
 for i:=1 to n do
 begin
  read(c[i]);
  for j:=1 to c[i] do read(a[i,j]);
 end;

 for I:=1 to n do
 for j:=1 to c[i] do
 begin
  if a[i,j]<v then
  begin
   s:=s+1;
   b[s]:=i;
   break;
  end;
 end;
 writeln(s);
 for i:=1 to s do write(b[i],' ');
 readln;
end.