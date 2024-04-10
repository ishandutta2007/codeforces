var a,x,y:longint;
begin
 readln(a,x,y);
 if y mod a=0 then begin writeln('-1');halt(0);end;
 if y div a=0 then
  if (abs(x)<a/2) then begin writeln('1');halt(0);end else begin writeln('-1');halt(0);end;
 if y div a mod 2=1 then 
  if (abs(x)<a/2) then begin writeln(y div a div 2+((y div a div 2+1)*2));halt(0);end else begin writeln('-1');halt(0);end;
 if y div a mod 2=0 then 
  if (x< a)and(x>0) then begin writeln(y div a div 2+(y div a div 2*2)+1);halt(0);end else
  if (x>-a)and(x<0) then begin writeln(y div a div 2+(y div a div 2*2));halt(0);end else
   begin writeln('-1');halt(0);end;
end.