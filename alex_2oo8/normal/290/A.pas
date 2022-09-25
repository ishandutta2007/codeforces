program problem1;

var	ans: array[ 1..40 ] of string;
	n: longInt;

begin
	ans[1] := 'Washington';
	ans[2] := 'Adams';
	ans[3] := 'Jefferson';
	ans[4] := 'Madison';
	ans[5] := 'Monroe';
	ans[6] := 'Adams';
	ans[7] := 'Jackson';
	ans[8] := 'Van Buren'; 
	ans[9] := 'Harrison';
	ans[10] := 'Tyler';
	ans[11] := 'Polk';
	ans[12] := 'Taylor';
	ans[13] := 'Fillmore'; 
	ans[14] := 'Pierce';
	ans[15] := 'Buchanan'; 
	ans[16] := 'Lincoln';
	ans[17] := 'Johnson';
	ans[18] := 'Grant';
	ans[19] := 'Hayes';
	ans[20] := 'Garfield';
	ans[21] := 'Arthur';
	ans[22] := 'Cleveland';
	ans[23] := 'Harrison';
	ans[24] := 'Cleveland';
	ans[25] := 'McKinley';
	ans[26] := 'Roosevelt';
	ans[27] := 'Taft';
	ans[28] := 'Wilson'; 
	ans[29] := 'Harding';
	ans[30] := 'Coolidge';
	ans[31] := 'Hoover';
	ans[32] := 'Roosevelt';
	ans[33] := 'Truman';
	ans[34] := 'Eisenhower';
	ans[35] := 'Kennedy';
	ans[36] := 'Johnson';
	ans[37] := 'Nixon';
	ans[38] := 'Ford';
	ans[39] := 'Carter';
	ans[40] := 'Reagan';
	
	readln( n );
	writeln( ans[n] );
end.