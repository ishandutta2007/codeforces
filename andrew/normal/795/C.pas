var
 s:ansistring;
 l,i,j,d:longint;
begin
 readln(l);
 s:='';
 if l mod 2<>0 then begin l:=l-3; d:=3; end;
 for i:=1 to l div 2 do s:=s+'1';
 for i:=1 to d div 3 do s:='7'+s;
 writeln(s);
end.