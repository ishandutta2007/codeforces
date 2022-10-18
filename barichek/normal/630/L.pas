uses math;
var
  s:string;
  dop1,dop2:int64;
  i:longint;
begin
  read(s);
  s:=s[1]+s[3]+s[5]+s[4]+s[2];
  val(s,dop1);
  dop2:=dop1;
  for i:=2 to 5 do
    dop1:=(dop1*dop2) mod 100000;
  str(dop1,s);
  for i:=1 to 5-length(s) do
   s:='0'+s;

  writeln(s);
end.