var a,b,s:int64;
function opr(x:int64):int64;
var s:int64;
begin
 if x>9 then s:=9 else begin s:=x;opr:=s;exit;end;
 if x>99 then s:=s+9 else begin if x div 10<=x mod 10 then s:=s+x div 10 else s:=s+x div 10-1;opr:=s;exit;end;
 if x>999 then s:=s+90 else begin if x div 100<=x mod 10 then s:=s+x div 10-9 else s:=s+x div 10-10;opr:=s;exit;end;
 if x>9999 then s:=s+900 else begin if x div 1000<=x mod 10 then s:=s+x div 10-99 else s:=s+x div 10-100;opr:=s;exit;end;
 if x>99999 then s:=s+9000 else begin if x div 10000<=x mod 10 then s:=s+x div 10-999 else s:=s+x div 10-1000;opr:=s;exit;end;
 if x>999999 then s:=s+90000 else begin if x div 100000<=x mod 10 then s:=s+x div 10-9999 else s:=s+x div 10-10000;opr:=s;exit;end;
 if x>9999999 then s:=s+900000 else begin if x div 1000000<=x mod 10 then s:=s+x div 10-99999 else s:=s+x div 10-100000;opr:=s;exit;end;
 if x>99999999 then s:=s+9000000 else begin if x div 10000000<=x mod 10 then s:=s+x div 10-999999 else s:=s+x div 10-1000000;opr:=s;exit;end;
 if x>999999999 then s:=s+90000000 else begin if x div 100000000<=x mod 10 then s:=s+x div 10-9999999 else s:=s+x div 10-10000000;opr:=s;exit;end;
 if x>9999999999 then s:=s+900000000 else begin if x div 1000000000<=x mod 10 then s:=s+x div 10-99999999 else s:=s+x div 10-100000000;opr:=s;exit;end;
 if x>99999999999 then s:=s+9000000000 else begin if x div 10000000000<=x mod 10 then s:=s+x div 10-999999999 else s:=s+x div 10-1000000000;opr:=s;exit;end;
 if x>999999999999 then s:=s+90000000000 else begin if x div 100000000000<=x mod 10 then s:=s+x div 10-9999999999 else s:=s+x div 10-10000000000;opr:=s;exit;end;
 if x>9999999999999 then s:=s+900000000000 else begin if x div 1000000000000<=x mod 10 then s:=s+x div 10-99999999999 else s:=s+x div 10-100000000000;opr:=s;exit;end;
 if x>99999999999999 then s:=s+9000000000000 else begin if x div 10000000000000<=x mod 10 then s:=s+x div 10-999999999999 else s:=s+x div 10-1000000000000;opr:=s;exit;end;
 if x>999999999999999 then s:=s+90000000000000 else begin if x div 100000000000000<=x mod 10 then s:=s+x div 10-9999999999999 else s:=s+x div 10-10000000000000;opr:=s;exit;end;
 if x>9999999999999999 then s:=s+900000000000000 else begin if x div 1000000000000000<=x mod 10 then s:=s+x div 10-99999999999999 else s:=s+x div 10-100000000000000;opr:=s;exit;end;
 if x>99999999999999999 then s:=s+9000000000000000 else begin if x div 10000000000000000<=x mod 10 then s:=s+x div 10-999999999999999 else s:=s+x div 10-1000000000000000;opr:=s;exit;end;
 if x>999999999999999999 then s:=s+90000000000000000 else begin if x div 100000000000000000<=x mod 10 then s:=s+x div 10-9999999999999999 else s:=s+x div 10-10000000000000000;opr:=s;exit;end;
 opr:=s;
end;
begin
 read(a,b);
 s:=opr(b)-opr(a-1);
 writeln(s);
end.