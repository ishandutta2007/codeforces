var i,a,b,n,s:longint;
begin
 readln(n,a,b);
 for i:=0 to b do
  if n-1-i>=a then inc(s);
 writeln(s);
end.