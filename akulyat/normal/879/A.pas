Program Dia;
var i,n,day,s,d:longint;


begin
read(n);
read(day, i);
for i:=2 to n do
  begin
  read(s,d);
  if day<s then
    day:=s else
      if day mod d< s mod (d) then
        day:=day-(day mod d)+(s mod (d)) else
          day:=day-(day mod d)+d+(s mod d);
  end;
writeln(day);



end.