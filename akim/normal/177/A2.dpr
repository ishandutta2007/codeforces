var n,s,v,i,f:longint;
begin
 readln(n);s:=0;
 for i:=1 to n do
  for f:=1 to n do
  begin
   read(v);
   if (i=f)or(n+1-i=f)or(n div 2+1=f)or(n div 2+1=i)then s:=s+v;
  end;
 writeln(s);
end.