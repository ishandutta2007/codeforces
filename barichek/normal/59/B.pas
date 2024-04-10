uses math;
var
  n,a,mini,knep,s:longint;
  i:longint;
begin
  read(n);
  mini:=10000000;
  knep:=0;
  s:=0;

  for i:=1 to n do
    begin
      read(a);
      inc(s,a);
      if a mod 2=1 then begin mini:=min(mini,a); inc(knep); end;
    end;

  if (s mod 2=0) and (knep=0) then begin writeln(0); halt; end;
  if knep mod 2=1 then writeln(s)
  else writeln(s-mini);
end.