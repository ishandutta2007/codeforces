var
 a,b,n,i,s,d,c:longint;
begin
 readln (n);
 for i:=1 to n do
 begin
  read(a);
  if a= -1 then
  begin
   if s=0  then c:=(c+1);
  if s<1  then c:=(c+1)-1;

   if s=0 then s:=0 else s:= s-1;
  end else
  begin
  s:=s+a;
  end;
 end;

 writeln(c);
 readln;
end.