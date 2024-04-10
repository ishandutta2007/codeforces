uses math;
var
  s,ans:string;
  k1,k2,k3:longint;
  i:longint;
begin
  readln(s);
  k1:=0;
  k2:=0;
  k3:=0;
  for i:=1 to length(s) do
    begin
      if s[i]='1' then inc(k1);
      if s[i]='2' then inc(k2);
      if s[i]='3' then inc(k3);
    end;
       if k1>0 then begin write(1); dec(k1); end
  else if k2>0 then begin write(2); dec(k2); end
  else              begin write(3); dec(k3); end;

  for i:=1 to k1 do
    write('+1');
  for i:=1 to k2 do
    write('+2');
  for i:=1 to k3 do
    write('+3');
end.