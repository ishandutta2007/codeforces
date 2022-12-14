var
 a,s1:array[0..1000] of longint;
 s,b,c,d,n,m,k,i,j,v,v1:longint;
begin
 s:=-1;
 readln(n);
 for i:=1 to n do
 begin
 v:=0;
  read(a[i]);
  if (a[i]=1) and (a[i-1]=1) then inc(v);
  if v=1 then inc(s);
  if (a[i]=1) and (v=0) then s:=s+2;

 end;
 if s=-1 then s:=0;
 writeln(s);
end.