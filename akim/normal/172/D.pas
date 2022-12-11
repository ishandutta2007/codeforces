var a:array[1..20000100]of longint;
    k,l,i,f,c,p,st,t:longint;s:int64;
begin
 readln(k,l);
 p:=k+l-1;
 c:=trunc(sqrt(k+l));
 for i:=1 to c do
 begin
  st:=sqr(i);
  t:=st;
  f:=1;
  while t<=p do
  begin
   a[t]:=f;
   inc(f);
   t:=t+st;
  end;
 end;
 for i:=k to p do
 begin
  s:=s+a[i];
 end;
 writeln(s);
end.