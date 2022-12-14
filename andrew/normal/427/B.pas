var
 a,s1:array[1..1000] of longint;
 s,b,c,x,n,m,k,i,j,v,v1,t:longint;
begin
 readln(n,t,c);
 for i:=1 to n do
 begin
  read(x);
  if x<=t then k:=k+1 else k:=0;
  if k>=c then inc(s);
 end;
 writeln(s);
end.