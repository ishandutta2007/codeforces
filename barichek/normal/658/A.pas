uses math;
var
  cost,time:array[1..10000]of longint;
  n,c,now:longint;
  ans1,ans2:longint;
  i:longint;
begin
  read(n,c);
  for i:=1 to n do
    read(cost[i]);
  for i:=1 to n do
    read(time[i]);

  for i:=1 to n do
    begin
      inc(now,time[i]);
      inc(ans1,max(0,cost[i]-c*now));
    end;
  now:=0;

  for i:=n downto 1 do
    begin
      inc(now,time[i]);
      inc(ans2,max(0,cost[i]-c*now));
    end;

  if ans1>ans2 then writeln('Limak')
  else if ans1<ans2 then writeln('Radewoosh')
  else writeln('Tie');
end.