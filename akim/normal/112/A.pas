var s,t:string;
begin
 readln(s);
 readln(t);
 if upcase(s)=upcase(t) then writeln(0) else
 if upcase(s)<upcase(t) then writeln(-1) else
 writeln(1);
end.