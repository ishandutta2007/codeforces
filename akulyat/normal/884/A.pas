Program Hate_NotHate_ButDontLove;
var i,n,t,time:longint;


begin
read(n,t);
for i:=1 to n do
  begin
  read(time);
  t:=t+time-86400;
  if t<=0 then 
    begin
    writeln(i);
    exit;
    end;
  end;




end.