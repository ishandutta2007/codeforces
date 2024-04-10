uses math;
var
  s,ans1,ans2:string;
  n,dop1,dop2:longint;
begin
  readln(s);
  read(n);
  val(copy(s,1,2),dop1);
  val(copy(s,4,2),dop2);
  dop1:=dop1*60+dop2;
  inc(dop1,n);
  dop1:=dop1 mod (24*60);
  str(dop1 div 60,ans1);
  str(dop1 mod 60,ans2);
  if length(ans1)=1 then ans1:='0'+ans1;
  if length(ans2)=1 then ans2:='0'+ans2;
  writeln(ans1,':',ans2);
end.