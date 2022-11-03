var a,b,i:longint;

begin
read(a,b);
while (a>0) and (b>0) do
begin
if b<a then
   begin
   b:=b+1;
   a:=a-2;
   if a>=0 then
   i:=i+1;
   end
   else
    begin
   b:=b-2;
   a:=a+1;
   if b>=0 then
   i:=i+1;
   end;
end;
   writeln(i);
   end.