var
 a,b,c,d,k,n,i:longint;
begin
 readln(n,k);
 for i:=1 to n do
 begin
  read(a);
  if a+k<=5 then
  begin
   c:=c+1;
  end;
  if c=3 then
  begin
   d:=d+1;
   c:=0;
  end;
 end;

 writeln(d);
 readln;
end.