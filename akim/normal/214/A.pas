var n,m,s,i:longint;
begin
 readln(n,m);
 for i:=0 to 1010 do
  if (n-sqr(i)>=0)and(i+sqr(n-sqr(i))=m) then inc(s);
 writeln(s);
end.