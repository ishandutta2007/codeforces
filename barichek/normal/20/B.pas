uses math;
var
  a,b,c,d:int64;
begin
  read(a,b,c);
  if (a=0) and (b<>0) then begin writeln(1); writeln(-c/b:0:10); halt; end;
  if (a=0) and (b=0) then
    if c=0 then begin writeln(-1); halt; end
    else begin writeln(0); halt; end;
  d:=b*b-4*a*c;
  if d>0 then begin writeln(2); writeln(min((-b+sqrt(d))/(2*a),(-b-sqrt(d))/(2*a)):0:10); writeln(max((-b-sqrt(d))/(2*a),(-b+sqrt(d))/(2*a)):0:10); end;
  if d=0 then begin writeln(1); writeln(-b/(2*a):0:10); end;
  if d<0 then writeln(0);
end.