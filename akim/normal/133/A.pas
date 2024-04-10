var s:string;k:longint;
begin
 readln(s);
 k:=pos('H',s);if k<>0 then begin writeln('YES');halt(0);end;
 k:=pos('Q',s);if k<>0 then begin writeln('YES');halt(0);end;
 k:=pos('9',s);if k<>0 then begin writeln('YES');halt(0);end;
 writeln('NO')
end.