var n,a,b,c,d,k,l,i:longint;
begin
 readln(n);c:=1000;d:=1000;
 for i:=1 to n do
 begin
  readln(a,b);
  if (a=c)and(b=d) then inc(k) else begin k:=1;c:=a;d:=b;end;
  if k>l then l:=k;
 end;
 writeln(l);
end.