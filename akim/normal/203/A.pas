var x,t,a,b,da,db,i,f:longint;
begin
 readln(x,t,a,b,da,db);
 for i:=0 to t-1 do
  for f:=0 to t-1 do
   if x=a-da*i+b-db*f then begin writeln('YES');halt(0);end;
 for i:=0 to t-1 do
  if x=a-da*i then begin writeln('YES');halt(0);end;
 for f:=0 to t-1 do
  if x=b-db*f then begin writeln('YES');halt(0);end;
 if x=0 then begin writeln('YES');halt(0);end;
 writeln('NO');
end.